#!/usr/bin/env python

"""
setup.py file for SWIG example
"""

from distutils.core import setup, Extension

SWObjects_module = Extension('_SWObjects',
                             sources=['swig/SWObjects_wrap.cpp',
                                      'lib/SWObjects.cpp',
                                      'lib/ResultSet.cpp',
                                      'lib/RdfDB.cpp',
                                      'lib/ParserCommon.cpp',
                                      'lib/TurtleSParser/TurtleSParser.cpp',
                                      'lib/TurtleSScanner.cpp',
                                      'lib/TrigSParser/TrigSParser.cpp',
                                      'lib/TrigSScanner.cpp'],
                             libraries=['boost_regex-mt'],
                             )

setup (name = 'SWObjects',
       version = '0.1',
       author      = "SWIG Docs",
       description = """Simple swig example from docs""",
       ext_modules = [SWObjects_module],
       py_modules = ["SWObjects"],
       )
