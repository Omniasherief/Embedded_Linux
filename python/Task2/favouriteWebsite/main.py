from favouriteWeb import get_choice,open_web
while True:
    choice=get_choice()
    if choice =='q':
        print("Exiting")
        break
    else:
        open_web(choice)
