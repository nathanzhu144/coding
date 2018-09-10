import requests

r = requests.get('https://api.github.com/events')
r = requests.post('http://httpbin.org/post', data = {'dog':'vcat'})

print(r.url)