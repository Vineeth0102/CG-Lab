import cv2
import matplotlib.pyplot as plt

# Read the image
image = cv2.imread('cat.jpg')
if image is None:
    print("Error: Could not read the image.")
    exit()

# Get the center of the image
center_y, center_x = image.shape[0] // 2, image.shape[1] // 2

# Split the image into quadrants
quadrants = [
    image[:center_y, :center_x],      # Top Left
    image[:center_y, center_x:],      # Top Right
    image[center_y:, :center_x],      # Bottom Left
    image[center_y:, center_x:]       # Bottom Right
]

# Convert BGR to RGB and display using Matplotlib
titles = ['Top Left', 'Top Right', 'Bottom Left', 'Bottom Right']
plt.figure(figsize=(10, 10))
for i, (quad, title) in enumerate(zip(quadrants, titles)):
    plt.subplot(2, 2, i + 1)
    plt.imshow(cv2.cvtColor(quad, cv2.COLOR_BGR2RGB))
    plt.title(f'{title} (by 4MT21CS156)')  # Add your name here
    plt.axis('off')

plt.tight_layout()
plt.show()
