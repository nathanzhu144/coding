import json

data = [1, 2, 3]
with open('data.txt', 'w') as outfile:
    json.dump(data, outfile)