import serial
import re
import csv
import sqlite3

conn = sqlite3.connect('tempdb.sqlite')
cur = conn.cursor()

cur.execute('DROP TABLE IF EXISTS Results')

        

cur.execute('''
                CREATE TABLE IF NOT EXISTS Results (
            temp_C REAL,
            temp_K REAL,
            temp_F REAL,
            humidity REAL ) ''')

ser = serial.Serial('/dev/ttyACM0',9600)
d = []


pattern = r"(\d{1,3}\.\d{1,2})"

float_lst = []

def convert_data(text):
    """ИЗВЛЕКАЕМ ТОЛЬКО ЦИФРЫ ИЗ ПОТОКА"""
        
    result = re.findall(pattern, text) #list
    #print(type(result))

    return result


def listconnect(lstlst):
    """ОБЪЕДИНЯЕМ СПИСОК СПИСКОВ В 1 СПИСОК ЗНАЧЕНИй"""
    all=[]
    for lst in lstlst:
        all.extend(lst)
    return all


def receive_data():
 
    data = ser.readline()  #read data from serial
    print(data)
    #print(type(data))
    if data is not None:
        
        strdata = str(data) #его будем извлекать по 1 значению
        #print(strdata)
                
        rez = convert_data(strdata)
        
        print("rez - (извлеченные цифры)", rez)
        print("rez type - ", type(rez))  #class 'list' of str
        
        
        return rez
 
def main_run():  
    limit = 4 # 4 значения получаем
    n = 0
    while n < limit:
        n += 1
    
        strdata2 = receive_data()
        d.append(strdata2)  #добавили строки в d
        #print("strdata2 - ", strdata2)
        print("d   -   ", d)
        v = listconnect(d) #получили 1 список строк
        print("v   -   ", v)
        
    for x in v:
    
        float_lst.append(float(x))
        
    print ("float_lst СРАЗУ ПОСЛЕ ДОБАВЛЕНИЯ", float_lst)
    
    row = cur.fetchone()
    #for m in float_lst:

    if row is None:
        cur.execute('''INSERT INTO Results (temp_C, temp_K, temp_F, humidity)
             VALUES (?, ?, ?, ?)''', (float_lst[0], float_lst[1], float_lst[2], float_lst[3]) )
    conn.commit()
    #del float_lst[:]
    float_lst.clear()
    d.clear()
    v.clear()
    

    
for go in range(50):
    print("float_lst - перед следующей итерацией", float_lst)
    main_run()
    float_lst.clear() 
    print("float_lst - МЕжДУ ЦИКЛАМИ ФУНКЦИИ", float_lst)
 

conn.commit()
cur.close()

    
#with open("result_file.log", 'w') as output_file:
#    writer = csv.writer(output_file)
#    writer.writerows(d)
#    output_file.close()
#with open("result_log.log", 'w') as log:
#    print("Результат - " + str(d[0]), file=log)

    

