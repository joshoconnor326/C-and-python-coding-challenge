#!/usr/bin/env python
# -*- coding: utf-8 -*-

'''
This script is used to demonstrate how dictionaries can be mutable when passed
to a function as a parameter.
    Task #1:
        Modify the 'main' function to allow the 'foo' key in the 'value'
        dictionary to be incremented by the 'incrementFoo' function.

        Expected Output:
            The foo key is intially set to: 0
            The foo key is now: 1
'''

def incrementFoo(value={'foo':1}):
    '''
    Increments the 'foo' key of a dictionary.
        @param value The dictionary containing 'foo', which is incremented.
    '''
    value['foo']=value['foo']+1

def main():
    '''
    Entry point, which is to be modified so that 'foo' in 'value' is
    incremented from '0' to '1'.
    '''
    value={'foo':0}
    print('The foo key is intially set to: %d' % value['foo'])
    incrementFoo(dict(value))
    print('The foo key is now: %d' % value['foo'])

if __name__ == '__main__':
    main()


