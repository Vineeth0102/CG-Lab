import cv2
import numpy as np
import matplotlib.pyplot as plt

# Read the image
image = cv2.imread('image.png')
if image is None:
    print("Error: Could not read the image.")
    exit()

# Convert to grayscale
gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

# Apply Canny edge detection
edges = cv2.Canny(gray_image, 100, 200)

# Find contours
contours, _ = cv2.findContours(edges, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

# Draw contours on the original image
contoured_image = image.copy()
cv2.drawContours(contoured_image, contours, -1, (0, 255, 0), 2)

# Display images using Matplotlib
titles = ['Original Image', 'Edges', 'Contours']
images = [image, edges, contoured_image]

plt.figure(figsize=(15, 5))
for i, (img, title) in enumerate(zip(images, titles)):
    plt.subplot(1, 3, i + 1)
    if title == 'Edges':
        plt.imshow(img, cmap='gray')
    else:
        plt.imshow(cv2.cvtColor(img, cv2.COLOR_BGR2RGB))
    plt.title(f'{title} (by 4MT21CS181)')
    plt.axis('off')

plt.tight_layout()
plt.show()
