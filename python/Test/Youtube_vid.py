

#download playlist

from pytube import Playlist # type: ignore

# Replace with the playlist URL
playlist_url = "https://www.youtube.com/playlist?list=PLkH1REggdbJpG8fHZvivt-5Hlg3UZcJrK"

# Create a Playlist object
playlist = Playlist(playlist_url)

# Loop through each video in the playlist
for video in playlist.videos:
  try:
    # Get the highest resolution stream
    highest_resolution = video.streams.get_highest_resolution()
    
    # Download the video with filename based on video title
    print(f"Downloading: {video.title}")
    highest_resolution.download(filename=f"{video.title}.mp4")
  except Exception as e:
    print(f"Error downloading {video.title}: {e}")

print("Playlist download complete!")