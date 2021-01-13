import time
import serial
import smtplib
 
TO
= ‘TheReceiverEmailAddress‘
USER
= ‘YourEmailAddress‘
PASS
= ‘YourEmailPassword‘
 
SUBJECT = ‘PIR-Motion-Information‘
BODY
= ‘Motion was detected!‘
 
COMPORT = ‘COM5‘
BAUDRATE = 9600
 
ser = serial.Serial(COMPORT, BAUDRATE)
 
motionCounter = 0
 
def sendEmail():
print ‘Try to send Email 
...‘
smtpserver = smtplib.SMTP(»smtp.gmail.com«, 587)
smtpserver.ehlo()
smtpserver.starttls()
smtpserver.ehlo
smtpserver.login(USER, PASS)
header = ‘To:‘ + TO + ‘\n‘ + ‘From: ‘ + USER
header = header + ‘\n‘ + ‘Subject:‘ + SUBJECT + ‘\n‘
print header
emailMsg = header + ‘\n‘ + BODY + ‘\n\n‘
smtpserver.sendmail(USER, TO, emailMsg)
smtpserver.close()
- orderid - 28582327 - transid - 28582327_3D -
while True:
msg = ser.readline() # Read serial informations
print ‘PIR-Motion-Sensor-Value: ‘ + msg
print ‘Motion-Counter: ‘ + str(motionCounter)
if msg[0] == ‘1‘:
motionCounter = motionCounter + 1
if motionCounter > 3:
sendEmail()
motionCounter = 0
if msg[0] == ‘0‘:
motionCounter = 0
