from urllib.request import urlopen
from bs4 import BeautifulSoup

r = 'http://olympus.realpython.org/profiles'
page = urlopen(r)
html_text = page.read().decode('utf-8')
soup = BeautifulSoup(html_text, "html.parser")

links = set()

for link in soup.find_all('a'):
    l = link.get('href')
    if l != None:
        links.add(l)

for link in links:
    print(f'{r[:-9]}{link}')
