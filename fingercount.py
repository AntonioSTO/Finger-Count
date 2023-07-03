import cv2
import mediapipe as mp

video = cv2.VideoCapture(0)

hand = mp.solutions.hands
Hand = hand.Hands(max_num_hands=1)
mpDraw = mp.solutions.drawing_utils

while True:
    check, img = video.read()
    imgRGB = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
    results = Hand.process(imgRGB)
    handPoints = results.multi_hand_landmarks
    h,w,d = img.shape
    font = cv2.FONT_HERSHEY_SIMPLEX
    pontos = []

    if handPoints:
        for points in handPoints:
            print(points)
            mpDraw.draw_landmarks(img,points,hand.HAND_CONNECTIONS)
            for id, cord in enumerate(points.landmark):
                cx,cy = int(cord.x*w), int(cord.y*h)
                # cv2.putText(img, str(id), (cx,cy+10), font, 0.3, (0,0,0), 2)
                pontos.append((cx,cy))
            
        dedos = [8,12,16,20]
        contador = 0

        if points:
            if pontos[4][0] < pontos[2][0]:
                contador += 1
            for x in dedos:
                if pontos[x][1] < pontos[x-2][1]:
                    contador += 1

        cv2.putText(img, str(contador), (100,100), font, 4, (0,0,0), 5)


    cv2.imshow("hands", img)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break




