import cImage
def main():
    img = cImage.Image("summer.jpg")
    newimg = cImage.EmptyImage(img.getWidth(),img.getHeight())
    win = cImage.ImageWin()
    for col in range(int((img.getWidth()/2))):
        for row in range(int((img.getHeight()/2))):
            p = img.getPixel(col,row)
            green = 255-p.getGreen()
            blue = 255-p.getBlue()
            red = 255-p.getRed()
            newpixel = cImage.Pixel(red,green,blue)
            newimg.setPixel(col,row,newpixel)
    for col in range(int((img.getWidth()/2)),img.getWidth()):
        for row in range(int((img.getHeight()/2))):
            p = img.getPixel(col,row)
            green = p.getGreen()
            blue = p.getBlue()
            red = p.getRed()
            newcolor = int((red+green+blue)/3)
            newpixel = cImage.Pixel(newcolor,newcolor,newcolor)
            newimg.setPixel(col,row,newpixel)
    for col in range(int((img.getWidth()/2)),img.getWidth()):
        for row in range(int((img.getHeight()/2)),img.getHeight()):
            p = img.getPixel(col,row)
            green = p.getGreen()
            blue = p.getBlue()
            red = p.getRed()
            newcolor = int((red+green+blue)/3)
            newpixel = cImage.Pixel(newcolor,newcolor,newcolor)
            newimg.setPixel(col,row,newpixel)
    for col in range(int((img.getWidth()/2)),img.getWidth()):
        for row in range(int((img.getHeight()/2)),img.getHeight()):
            p = img.getPixel(col,row)
            red = p.getRed()
            if red > 140:
                val = 255
            else:
                val = 0
            newpixel = cImage.Pixel(val,val,val)
            newimg.setPixel(col,row,newpixel)
    for col in range(int((img.getWidth()/2))):
        for row in range(int((img.getHeight()/2)),img.getHeight()):
            p = img.getPixel(col,row)
            green = 0
            blue = p.getBlue()
            red = p.getRed()
            newpixel = cImage.Pixel(red,green,blue)
            newimg.setPixel(col,row,newpixel)
    newimg.draw(win)
    win.exitonclick()
main()
