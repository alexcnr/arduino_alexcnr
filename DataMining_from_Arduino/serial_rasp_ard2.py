import serial
import re
import csv



ser = serial.Serial('/dev/ttyACM0',9600)
d = []
s2 = []

pattern = r"(\d{1,3})"

def convert_data(text):
        
    result = re.findall(pattern, text) #list
    #print(type(result))

    return result
  
def receive_data():
    data = ser.readline()  #read data from serial
    print(data)
    if data:
        strdata = str(data)
        #print(strdata)
        return strdata
n = 0
limit = 30

while n < limit:
    n += 1 
    strdata = receive_data()
    rez = convert_data(strdata)
    print("rez - ", rez)
    print("rez type - ", type(rez))
    for i in rez:
        x = str(i)
        result2 = re.match(r"(^0$)", x)
        print("result2 - ", result2)
        if result2 is None:
            d.append(i)

print(d)
    
with open("result_file.csv", 'w+') as output_file:
    writer = csv.writer(output_file)
    writer.writerows(d)
    output_file.close()



    

