import webbrowser

fav_web={"1":"https://www.youtube.com/",
         "2":"https://www.facebook.com/",
         "3":"https://www.goodreads.com/"}


def get_choice():
    print("Favourite Websites")
    choice=input("Enter your choice\n 1 for youtube\n 2 for Facebook\n 3 for goodreads \n  q to quit")
    return choice.lower()

def open_web(choice):
    if choice in fav_web:
        url=fav_web[choice]
        webbrowser.open(url)
    else:
        print(f"Invalid choice{choice}")   



