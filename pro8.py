import cv2
import numpy as np
import matplotlib.pyplot as plt

# Read the image
image = cv2.imread('cat.jpg')
if image is None:
    print("Error: Could not read the image.")
    exit()

# Get image dimensions
height, width = image.shape[:2]

# Rotation
angle = 45  # Rotate by 45 degrees
rotation_matrix = cv2.getRotationMatrix2D((width // 2, height // 2), angle, 1)
rotated_image = cv2.warpAffine(image, rotation_matrix, (width, height))

# Scaling
scale_factor = 3.5  # Scale by 1.5 times
scaled_image = cv2.resize(image, None, fx=scale_factor, fy=scale_factor, interpolation=cv2.INTER_LINEAR)

# Translation
tx, ty = 100, 50  # Translate by 100 pixels right and 50 pixels down
translation_matrix = np.float32([[1, 0, tx], [0, 1, ty]])
translated_image = cv2.warpAffine(image, translation_matrix, (width, height))

# Display images using Matplotlib
titles = ['Original', 'Rotated', 'Scaled', 'Translated']
images = [image, rotated_image, scaled_image, translated_image]

plt.figure(figsize=(12, 12))
for i, (img, title) in enumerate(zip(images, titles)):
    plt.subplot(2, 2, i + 1)
    plt.imshow(cv2.cvtColor(img, cv2.COLOR_BGR2RGB))
    plt.title(f'{title} (by 4MT21CS181)')
    plt.axis('off')

plt.tight_layout()
plt.show()
