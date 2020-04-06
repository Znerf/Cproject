import os


a= os.listdir("E:/Train Har/not")
counter=0
for i in a:

	b="E:/Train Har/not/"+"d"+str(counter)+".bmp"
	os.rename("E:/Train Har/not/"+i,b)
	counter=counter+1


os.exit()


