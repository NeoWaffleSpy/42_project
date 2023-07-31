import csv
import sys
import matplotlib.pyplot as plt
import numpy as np

def getData(filename: str):
	with open(filename, 'r') as csv_file:
		try:
			dict_val = csv.reader(csv_file)
			data = list()
			for index, row in enumerate(dict_val):
				if index < 1:
					continue
				data.append(list((int(row[0]), int(row[1]))))
		except:
			sys.exit("Error: File {:} cannot be read".format(csv_file))
	return data

data = getData("data.csv")
dataX = list()
dataY = list()
spanX = list()
spanY = list()
for row in data:
	dataX.append(row[0])
	dataY.append(row[1])
	if len(spanX) == len(spanY) == 0:
		spanX.append(row[0])
		spanX.append(row[0])
		spanY.append(row[1])
		spanY.append(row[1])
		continue
	if spanX[0] > row[0]: spanX[0] = row[0]
	if spanX[1] < row[0]: spanX[1] = row[0]
	if spanY[0] > row[1]: spanY[0] = row[1]
	if spanY[1] < row[1]: spanY[1] = row[1]

# print("value range X: " + str(spanX[0]) + " - " + str(spanX[1]))
# print("value range Y: " + str(spanY[0]) + " - " + str(spanY[1]))
offsetX = (abs(spanX[1]) if abs(spanX[0]) < abs(spanX[1]) else abs(spanX[0])) / 10
offsetY = (abs(spanY[1]) if abs(spanY[0]) < abs(spanY[1]) else abs(spanY[0])) / 10
spanX[0] -= offsetX
spanX[1] += offsetX
spanY[0] -= offsetY
spanY[1] += offsetY

plt.style.use('dark_background')
# print(plt.style.available)
# size and color:
sizes = np.random.uniform(30, 30, len(dataX))
colors = np.random.uniform(15, 80, len(dataX))

# plot

fig, ax = plt.subplots()

ax.scatter(dataX, dataY, s=sizes, c=colors, vmin=0, vmax=100)
ax.set_xlim(xmin=spanX[0], xmax=spanX[1])
ax.set_ylim(ymin=spanY[0], ymax=spanY[1])

plt.show()

# model = open("model.csv", "tw")