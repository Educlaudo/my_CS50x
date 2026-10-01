import os
import qrcode

img = qrcode.make("https://www.youtube.com/watch?v=RQn34klqSQI")
img.save("chopin_scherzo2_qr.png", "PNG")
