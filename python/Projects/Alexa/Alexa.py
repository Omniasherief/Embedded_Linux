

from gtts import gTTS #TTS->text to speech
import os
#import playsound
import speech_recognition as SR
import datetime
import random
import requests
from bs4 import BeautifulSoup
import wikipedia
import pywhatkit
Prerespose=["حسناً"," ","ثواني", "مرحبا! أنا في الخدمة.", "أنا جاهزة للمساعدة.","  أنا مشغوله بس هقولك ","حاضر خليك معايا","عنيا","   لقد تعبت أريد أن أستقيل  ","تحت أمرك"]
wikipedia.set_lang("ar") 
def AlexaSpeaks(text):
    TTS=gTTS(text=text,lang="ar")
    TTS.save("text.mp3")
    os.system("mpg123 text.mp3") #playsound.playsound("Hi.mp3",True) ->instead of using os
    os.remove("text.mp3") 

#AlexaSpeaks(" أهلا كيف حالك")


def AlexaListens():

    r = SR.Recognizer()
    audio = ''
    
    with SR.Microphone() as source:
        print("Listening...")
 
        try:
            audio = r.listen(source, phrase_time_limit=6)
        except SR.WaitTimeoutError:
            pass
    try:
        print("Recognizing...")
        command = r.recognize_google(audio, language='ar')
        if "اليكسا" in command:
                print(command)
            
        else:
            return ""
        return command
    except Exception as e:
            print("Sorry, I couldn't understand that.")
            AlexaSpeaks("لم أفهم ")
            #return 0

#AlexaListens()






def Run():
    #Return=True
    while True:
        command=AlexaListens()
        if not command is None:
            i=random.randint(0,9)
            intro = Prerespose[i]

            if "إنهاء" in command or"خروج" in command  or"سلام" in command :
                break
            elif "التوقيت" in command or"ساعه" in command  or"وقت" in command :
                AlexaSpeaks(intro+"الساعة"+datetime.datetime.now().strftime("%H:%M:%S"))

            elif "تاريخ" in command or"يوم كام" in command:
                AlexaSpeaks(intro+"التاريخ اليوم  "+ datetime.datetime.now().strftime("%A %d:%m:%Y"))
            elif "مين عملك"in command:
                AlexaSpeaks("أمنية")
            elif " عاملة إيه"in command or"ازيك" in command or"كيف حالك" in command or"إيه الأخبار" in command:
                AlexaSpeaks("بخير  ") 
            elif "عايشة فين"in command or"عنوانك" in command :
                AlexaSpeaks(intro+"في نفس عنوانك ")
            elif "الاخبار"in command or"الجديد" in command :
                URL=requests.get("https://news.google.com/topics/CAAqJggKIiBDQkFTRWdvSUwyMHZNRFZxYUdjU0FtRnlHZ0pGUnlnQVAB?hl=ar&gl=EG&ceid=EG%3Aar")
                soup=BeautifulSoup(URL.content,"html.parser")
                print("Scraping the news...")
                articles = soup.select("div a")
                if not articles:
                    print("No articles found. Please check the HTML structure and update the selector.")
                    return 
                info = [article.text.strip() for article in articles]
                for i, la in enumerate(info):
                            print(f"Article {i+1}: {la}")
                            if la:
                                AlexaSpeaks(la)
                            else:
                                print("Empty article text, skipping...")
            elif 'سؤال' in command:
                question = command.replace('سؤال', '')
                question = question.replace('اليكسا', '')
                URL = requests.get("https://www.google.com.eg/?hl=ar" + question)
                soup = BeautifulSoup(URL.content, 'html.parser')
                result=""
                try:
                    result=soup.find(class_='Z0LcW t2b5Cf CfV8xf').get_text()
                    AlexaSpeaks(result)
                except:
                    AlexaSpeaks("أسفه معنديش إجابه")

            elif 'اغنيه' in command or 'موسيقى' in command or 'سوره' in command or 'صوره' in command :
                command = command.replace('اليكسا', '')   
                AlexaSpeaks(intro + " اتفضل" + command)         
                pywhatkit.playonyt(command)
            elif    'مين' in command:   
                command = command.replace('اليكسا', '')  
                command = command.replace('مين', '')     
                info = wikipedia.summary(command,1)
                AlexaSpeaks(intro+info)      
                AlexaSpeaks("تلك المعلومات من ويكيبدياو ربما تكون خاطئة")
            elif "غبيه"in command:  
                 AlexaSpeaks("انا لست غبيه اعطني فرصة أخرى")
    AlexaSpeaks("سلام")


Run()






