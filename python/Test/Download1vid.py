from pytube import YouTube


video_link = "https://www.youtube.com/watch?v=vGiLCneOyX4"  # Replace with your video URL
yt = YouTube(video_link)

# Get the available streams
streams = yt.streams


highest_resolution = streams.get_highest_resolution()

highest_resolution.download()