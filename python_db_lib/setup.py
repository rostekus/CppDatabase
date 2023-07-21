# setup.py

from setuptools import setup, find_packages

setup(
    name='python_db_lib',
    version='0.1.0',
    author='Rostyslav Movorov',
    description='Simple Python library for my Database written in C++',
    packages=find_packages(),
    install_requires=[
    'requests>=2.26.0',
        ],
)

