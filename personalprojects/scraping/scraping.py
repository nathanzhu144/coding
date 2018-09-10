"""http://docs.python-requests.org/en/master/
https://realpython.com/python-web-scraping-practical-introduction/
"""

from requests import get
from requests.exceptions import RequestException
from contextlib import closing
from bs4 import BeautifulSoup

def simple_get(url):
    """
    Attempts to get 
    """
    try:
        with closing(get(url, stream=True)) as resp:
            if is_good_response(resp):
                return resp.content
            else:
                return None
    except RequestException as e:
        log_error('Error during requests to {0}:{1}'.format(str(e)))
        return None

def is_good_response()

"""from mathematicians import simple_get"""

raw_html = simple_get('https://realpython.com/blog/')
print(len(raw_html))