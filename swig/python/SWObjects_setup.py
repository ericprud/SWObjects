#!/usr/bin/env python

"""
setup.py file for SWIG SWObjects
"""

from distutils.core import setup, Extension


SWObjects_module = Extension('_SWObjects',
                             sources=['swig/python/SWObjects_wrap.cxx',
                                      'lib/ParserCommon.cpp',
                                      'lib/TrigSParser/TrigSParser.cpp',
                                      'lib/TrigSScanner.cpp'
                                      ],
                             libraries=['boost_regex-mt'],
                             )

setup (name = 'SWObjects',
       version = '0.1',
       author      = "SWIG Docs",
       description = """Simple swig SWObjects from docs""",
       ext_modules = [SWObjects_module],
       py_modules = ["SWObjects"],
       )
