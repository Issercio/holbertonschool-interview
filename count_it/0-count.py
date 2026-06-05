#!/usr/bin/python3
"""
0-count.py
"""
import requests


def count_words(subreddit, word_list, after=None, counts=None):
    """
    Recursively queries the Reddit API, parses the titles of hot articles,
    and prints a sorted count of given keywords.
    """
    if counts is None:
        counts = {}

    headers = {'User-Agent': 'holberton-interview-task'}

    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)

    params = {
        'limit': 100,
        'after': after
    }

    response = requests.get(
        url,
        headers=headers,
        params=params,
        allow_redirects=False
    )

    if response.status_code != 200:
        return

    data = response.json().get('data', {})
    posts = data.get('children', [])

    # Normalize keywords to lowercase
    lower_words = [word.lower() for word in word_list]

    for post in posts:
        title = post.get('data', {}).get('title', '').lower()
        title_words = title.split()

        for word in lower_words:
            counts[word] = counts.get(word, 0) + title_words.count(word)

    after = data.get('after')

    # Recursive call if more pages exist
    if after is not None:
        return count_words(subreddit, word_list, after, counts)

    # Sort by count descending, then alphabetically ascending
    sorted_counts = sorted(
        counts.items(),
        key=lambda item: (-item[1], item[0])
    )

    for word, count in sorted_counts:
        if count > 0:
            print("{}: {}".format(word, count))
