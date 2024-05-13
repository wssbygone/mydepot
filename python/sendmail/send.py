import smtplib
from email.mime.text import MIMEText
from email.header import Header
from email.utils import formataddr
from datetime import datetime

def send_email(sender, auth_code, recipient, subject, body):
    # 邮件服务器配置
    smtp_server = 'smtp.qq.com'
    smtp_port = 465  # SSL端口号

    # 创建邮件对象
    message = MIMEText(body, 'plain', 'utf-8')
    message['From'] = formataddr((Header('发件人昵称', 'utf-8').encode(), sender))
    message['To'] = formataddr((Header('收件人昵称', 'utf-8').encode(), recipient))
    message['Subject'] = Header(subject, 'utf-8')

    try:
        # 建立安全连接
        with smtplib.SMTP_SSL(smtp_server, smtp_port) as server:
            # 登录邮箱
            server.login(sender, auth_code)
            # 发送邮件
            server.sendmail(sender, [recipient], message.as_string())
            print("邮件发送成功")
    except smtplib.SMTPException as e:
        print("邮件发送失败，错误信息：", e)

# 发件人和授权码
sender_email = 'mail@qq.com'
sender_auth_code = 'xxx'  # 替换为你的授权码

# 收件人地址
recipient_email = 'aaa@eye.cc'

now=datetime.now()
# 邮件标题和正文
email_subject = '这是一份测试邮件 ' + now.strftime("%Y-%m-%d %H:%M:%S")
email_body = '这是测试邮件的正文内容'

# 发送邮件
send_email(sender_email, sender_auth_code, recipient_email, email_subject, email_body)

