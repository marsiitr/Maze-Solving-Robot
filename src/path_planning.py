import cv2
import numpy as np
import urllib3.request

ux=1233    # initial x_coordinate
uy=701     # initial y_coordinate
vx=25      # final x_coordinate
vy=570     # final y_coordinate


img = cv2.imread('C:/Users/Yash Asati/Downloads/m.jpg', 1)   ## reading of maze image(this must be done by webcam itself)
img1 = cv2.imread('C:/Users/Yash Asati/Downloads/m.jpg', 1)
parentx = np.zeros((2000, 2000)) # x_coordinate of parent of each node
parenty = np.zeros((2000, 2000)) # y_coordinate of parent of each node
visited = np.zeros((1800, 1800)) # visited nodes(here coordinates)

a = [[ux,uy]]
b = [[ux,uy]]
p = []
c = 0
while (1):
    a = b
    b = []
    end = 0
    for i in a:
        if i[0] == vx and i[1] == vy:
            end = 1
            p = i
            break
        if visited[i[0], i[1]] != 1:
            visited[i[0], i[1]] = 1
        else:
            continue
        r = [i[0], i[1] + 1]
        l = [i[0], i[1] - 1]
        d = [i[0] - 1, i[1]]
        u = [i[0] + 1, i[1]]
        if img[i[0]][i[1]][0] < 150 and img[i[0]][i[1]][1] < 150 and img[i[0]][i[1]][2] < 150:
            continue
        if r not in a and visited[r[0], r[1]] != 1:
            b.append(r)
            if parentx[r[0], r[1]] == 0:
                parentx[r[0],r[1]] = i[0]
                parenty[r[0], r[1]] = i[1]
        if l not in a and visited[l[0], l[1]] != 1:
            b.append(l)
            if parentx[l[0], l[1]]==0:
                parentx[l[0], l[1]] = i[0]
                parenty[l[0], l[1]] = i[1]
        if d not in a and visited[d[0], d[1]] != 1:
            b.append(d)
            if parentx[d[0], d[1]] == 0:
                parentx[d[0], d[1]] = i[0]
                parenty[d[0], d[1]] = i[1]
        if u not in a and visited[u[0], u[1]] != 1:
            b.append(u)
            if parentx[u[0], u[1]] == 0:
                parentx[u[0], u[1]] = i[0]
                parenty[u[0], u[1]] = i[1]
        img[i[0]][i[1]] = [100,100,0]

    if c%10==0:
        imS = cv2.resize(img, (800, 700))
        cv2.imshow('img', imS)
        cv2.waitKey(1)
    c = c + 1
    if end == 1:
        break

print(c)
path = []

while(1):
    if p==[ux,uy]:
        break
    j=int(p[0])
    k=int(p[1])
    path.append([parentx[j,k],parenty[j,k]] )
    p = [parentx[j,k],parenty[j,k]]

realpath = []
j=[vy,vx]
for i in path:
    n=int(i[1])
    m=int(i[0])
    cv2.line(img1,(n,m),(j[0],j[1]),[0,0,100],7)
    j=[n,m]
    realpath.append(j)
    imS2 = cv2.resize(img1, (800, 700))
    cv2.imshow('img1',imS2)
    cv2.waitKey(1)
print(realpath)
path=realpath
imS1 = cv2.resize(img1, (800, 700))
cv2.imshow('img1', imS1)
cv2.waitKey(0)
cv2.destroyAllWindows()

##########################################################################################
##Live_coordinate_detection
##########################################################################################
pathsize=0
for l in path:
    pathsize+=1
global x1
global y1
global pa
pa=0
cap = cv2.VideoCapture(0)

while(1):

    ret,inputImage = cap.read()

    def display(im, bbox,pa):    # Display barcode and QR code location
        n = len(bbox)
        print(bbox)
        x1 = 0
        y1 = 0

        for coor in bbox:
            cv2.circle(im,(coor[0][0],coor[0][1]),7,[255,0,0],-1)
            x1 +=coor[0][0]
            y1 +=coor[0][1]

        font = cv2.FONT_HERSHEY_SIMPLEX
        strp = str(int(x1/4))+","+str(int(y1/4))
        cv2.putText(im,strp,(int(x1/4),int(y1/4)),font,1,[0,0,255],4)
        cv2.imshow("Results", im)

        if (int(x1 / 4) == path[pa][0] and int(y1 / 4) == path[pa][1]): # sending coordinates to NodeMCU
            x = str(path[pa][0])
            y = str(path[pa][1])
            i = "?x=" + x
            j = "?y=" + y
            url = "http://192.168.137.201/"
            url = url + str(i) + " " + str(j)
            print(url)
            http = urllib3.PoolManager()
            response = http.request('GET', url)
            pa+=1


    qrDecoder = cv2.QRCodeDetector()


    data, bbox, rectifiedImage = qrDecoder.detectAndDecode(inputImage)         # Detect and decode the qrcode
    if len(data) > 0:
        print("Decoded Data : {}".format(data))
        display(inputImage, bbox,pa)
        rectifiedImage = np.uint8(rectifiedImage);
        cv2.imshow("Rectified QRCode", rectifiedImage);
    else:
        print("QR Code not detected")
        cv2.imshow("Results", inputImage)
    if (pa==pathsize):
        break
    cv2.waitKey(1)
cv2.destroyAllWindows()
