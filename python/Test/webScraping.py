import requests
from bs4 import BeautifulSoup
import csv
from itertools import zip_longest

JopTitle=[]
CompanyName=[]
LocationOfCompany=[]
skill=[]
Links=[]
date=[]
#Responsibility=[]
# fetch url
pageNo=0

while True:
    try:
       
      url=requests.get(f"https://wuzzuf.net/search/jobs/?a=hpb%7Cspbg&q=telecom%20MAINTANCE%20engineering&start={pageNo}")

      #save page content
      PageContent=url.content  #print(PageContent)

      soup=BeautifulSoup(PageContent,"lxml")

      page_limit=int(soup.find("strong").text)
      print(page_limit)
      if(pageNo > (page_limit// 15)):       #//int div
         print("Page Ended")
         break
      #info we need
      JopTitles=soup.find_all("h2",{"class":"css-m604qf"})    #INCEPT ->DEVELOPER TOOL -> LINK TAG

      CompanyNames=soup.find_all("a",{"class":"css-17s97q8"}) 

      Locations=soup.find_all("span",{"class":"css-5wys0k"}) 

      Experience=soup.find_all("div",{"class":"css-y4udm8"}) 

      posted_new=soup.find_all("div",{"class":"css-4c4ojb"}) 

      posted_old=soup.find_all("div",{"class":"css-do6t5g"}) 
      posted=[*posted_new,*posted_old]

      #returned lists to extract needed info into other lists
      for i in range (len(JopTitles)):
         JopTitle.append(JopTitles[i].text)
         Links.append(JopTitles[i].find("a").attrs["href"])
         CompanyName.append(CompanyNames[i].text)
         LocationOfCompany.append(Locations[i].text)
         skill.append(Experience[i].text)
         date.append(posted[i].text)

         pageNo += 1
         print("page switched")
         print(pageNo)
    except:
        print("ERROR")
        break
'''
for link in Links:
     URL2=requests.get(link)
     Content2=URL2.content
     soup=BeautifulSoup(Content2,"lxml")
     requirements=soup.find("div",{"class":"css-1t5f0fr"}).ul
     respond_text=""
     for l in requirements.find_all("li"):
          respond_text+= l.text+" - "
     Responsibility.append(respond_text)     
'''


#create csv file and fill it
list=[JopTitle,CompanyName,date, LocationOfCompany,skill,Links] 
exported =zip_longest(*list) # *->unpacking 

try:
    with open("/home/omnia/Documents/csv/jobtest.csv", "w") as myfile:
        Writer = csv.writer(myfile)
        Writer.writerow(["job titles ", "company names", "Date", "locations", "skills", "Links"])
        Writer.writerows(exported)
except Exception as e:
    print("Error writing to CSV file:", e)


