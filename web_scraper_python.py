import requests
from bs4 import BeautifulSoup

# getting the webpage
page = requests.get('https://www.example.com')

# creating a BeautifulSoup object
soup = BeautifulSoup(page.text, 'html.parser')

# extracting all the <a> tags into a list
links = soup.findAll('a')

# going through each link
for link in links:
    # getting the link url
    url = link.get('href')

    # printing out the url
    print(url)
