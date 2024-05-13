import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
from email.mime.base import MIMEBase
from email import encoders

# 邮件信息配置
smtp_server = "smtp.qq.com"
smtp_port = 587
from_addr = "mail@qq.com"
password = "xxx"
to_addrs = ["aaa@eye.cc", "mail@qq.com"]
subject = "这是一份测试邮件"

# 创建邮件对象
msg = MIMEMultipart()
msg['From'] = from_addr
msg['To'] = ", ".join(to_addrs)
msg['Subject'] = subject

# 设置邮件正文
body = "这是一封带有附件的测试邮件。"
msg.attach(MIMEText(body, 'plain'))

# 添加附件1
filename1 = "send.py"
with open(filename1, "rb") as attachment:
    part = MIMEBase('application', 'octet-stream')
    part.set_payload(attachment.read())
    encoders.encode_base64(part)
    part.add_header('Content-Disposition', f"attachment; filename= {filename1}")
    msg.attach(part)

# 添加附件2
filename2 = "send_more_and_more_attach.py"
with open(filename2, "rb") as attachment:
    part = MIMEBase('application', 'octet-stream')
    part.set_payload(attachment.read())
    encoders.encode_base64(part)
    part.add_header('Content-Disposition', f"attachment; filename= {filename2}")
    msg.attach(part)

# 使用SMTP服务器发送邮件
try:
    with smtplib.SMTP(smtp_server, smtp_port) as server:
        server.starttls()  # 启动TLS加密
        server.login(from_addr, password)
        server.sendmail(from_addr, to_addrs, msg.as_string())
        print("邮件发送成功")
except Exception as e:
    print(f"邮件发送失败: {e}")

