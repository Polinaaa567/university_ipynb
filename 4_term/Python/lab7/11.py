import numpy as np
from PIL import Image


def bw_convert(image):
    arr = np.asarray(image, dtype='uint8')

    k = np.array([[[0.2989, 0.587, 0.114]]])
    sums = np.round(np.sum(arr * k, axis=2)).astype(np.uint8)
    arr2 = np.repeat(sums, 3).reshape(arr.shape)

    image2 = Image.fromarray(arr2)
    return image2.save('malina_bw.jpg')


bw_convert(Image.open('malina.jpg'))
