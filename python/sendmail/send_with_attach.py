import smtplib
from email import encoders
from email.mime.base import MIMEBase
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
from email.utils import formataddr
from email.header import Header
from datetime import datetime

def send_email_with_attachment(sender, auth_code, recipient, subject, body, attachment_path):
    # 邮件服务器配置
    smtp_server = 'smtp.qq.com'
    smtp_port = 465  # SSL端口号

    # 创建MIMEMultipart对象，用于组合不同类型的邮件内容
    message = MIMEMultipart()
    message['From'] = formataddr((Header('发件人昵称', 'utf-8').encode(), sender))
    message['To'] = formataddr((Header('收件人昵称', 'utf-8').encode(), recipient))
    message['Subject'] = Header(subject, 'utf-8')

    # 添加邮件正文
    message.attach(MIMEText(body, 'plain', 'utf-8'))

    # 添加附件
    with open(attachment_path, 'rb') as attachment_file:
        # 创建一个MIMEBase对象
        mime_base = MIMEBase('application', 'octet-stream')
        # 将附件内容读入到MIMEBase对象中
        mime_base.set_payload(attachment_file.read())
        # 编码附件内容
        encoders.encode_base64(mime_base)
        # 添加附件头信息
        mime_base.add_header('Content-Disposition', 'attachment', filename=Header(attachment_path, 'utf-8').encode())
        # 将MIMEBase对象添加到MIMEMultipart对象中
        message.attach(mime_base)

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
sender_auth_code = 'xxxx'  # 替换为你的授权码

# 收件人地址
recipient_email = 'aaa@eye.cc'

# 邮件标题和正文
now=datetime.now()
email_subject = '这是一份带附件的测试邮件 ' + now.strftime("%Y-%m-%d %H:%M:%S")
email_body = '这是测试邮件的正文内容。附件请查收。'

# 附件路径
attachment_file_path = 'send_with_attach.py'  # 替换为你的附件路径

# 发送邮件
send_email_with_attachment(sender_email, sender_auth_code, recipient_email, email_subject, email_body, attachment_file_path)

