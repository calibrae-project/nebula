from setuptools import setup

setup( name='nebuladebugnode',
       version='0.1',
       description='A wrapper for launching and interacting with a Steem Debug Node',
       url='http://github.com/steemit/steem',
       author='Steemit, Inc.',
       author_email='vandeberg@steemit.com',
       license='See LICENSE.md',
       packages=['nebuladebugnode'],
       #install_requires=['steemapi'],
       zip_safe=False )