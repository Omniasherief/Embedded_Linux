import tkinter as tk
from tkinter import messagebox
import pandas as pd
import ttkbootstrap as ttk
from ttkbootstrap.constants import *

# Function to calculate and update values
def calculate_average():
    try:
        df = pd.read_csv("sensor_data.csv")
        df.columns = df.columns.str.strip()  # Remove spaces in column names

        # Convert timestamps to datetime (not needed if no plotting, but ensures proper parsing)
        df["Timestamp"] = pd.to_datetime(df["Timestamp"])

        avg_temp = df["Temperature (°C)"].mean()
        avg_humidity = df["Humidity (%)"].mean()
        result_label.config(text=f"🌡 Avg Temp: {avg_temp:.2f}°C\n💧 Avg Humidity: {avg_humidity:.2f}%")

    except Exception as e:
        messagebox.showerror("Error", f"Could not load data:\n{e}")

# Auto refresh every 5 seconds
def auto_refresh():
    calculate_average()
    root.after(5000, auto_refresh)  # Refresh every 5000ms (5s)

# Tkinter setup
root = ttk.Window(themename="darkly")  # Dark mode theme
root.title("Sensor Data Monitor")
root.geometry("400x300")

# Title label
title_label = ttk.Label(root, text="📊 Sensor Data Monitor", font=("Arial", 18, "bold"))
title_label.pack(pady=10)

# Result display
result_label = ttk.Label(root, text="Loading data...", font=("Arial", 14))
result_label.pack(pady=10)

# Update button
update_button = ttk.Button(root, text="🔄 Update Now", command=calculate_average, bootstyle="primary")
update_button.pack(pady=10)

# Start auto-refreshing
auto_refresh()

# Run the Tkinter event loop
root.mainloop()
