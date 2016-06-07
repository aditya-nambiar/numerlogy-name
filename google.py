import time
import os
from selenium import webdriver
from random import randint

driver = webdriver.Chrome('/Users/aditya/Downloads/chromedriver')
f = open('half1.txt')
## Read the first line 
line = f.readline()

#search_query = "https://www.google.com/#q=" + line
bing_search = "https://www.bing.com/search?q="+line+"&qs=n&form=QBRE"
driver.get(bing_search)
time.sleep(3)

outp = open('boy.csv', 'w')
## If the file is not empty keep reading line one at a time
## till the file is empty
x = randint(30, 50)
while line:
    line = f.readline()
    #search_query = "https://www.google.com/#q=" + line
    bing_search = "https://www.bing.com/search?q=%2B"+line+"+boy+name&qs=n&form=QBRE"
    driver.get(bing_search)
    
    time.sleep(randint(15,30)/10)
    if x == 0 :
    	time.sleep(5)
    	x = x = randint(30, 50)
    x = x -1
 
    try:
        results = driver.find_element_by_xpath('//*[@id="b_tween"]/span[1]').text
        arr = results.split(" ")
        outp.write(line.rstrip() + ", " + arr[0] +"\n")
    except:
		outp.write(line.rstrip() + ", 0\n")
f.close()

outp.close()
