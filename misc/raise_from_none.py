#!/usr/bin/env python3

"""\
    Raise from None
    ===============

    Break the exception chaining in Python 3.
"""

try:
    raise Exception('i need to be raised')
except:
    # raise Exception('yes you can')
    raise Exception('no you cant') from None
