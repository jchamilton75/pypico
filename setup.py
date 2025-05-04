import sys
import sysconfig
from setuptools import setup
from setuptools.command.build_ext import build_ext
from setuptools.extension import Extension
from packaging.version import Version, InvalidVersion

# --- Version checks ---
skip_version_check = '--skip_version_check' in sys.argv
if skip_version_check:
    sys.argv.remove('--skip_version_check')
else:
    skipmsg = "Run with --skip_version_check to suppress this error (PICO may not work correctly)."
    if sys.version_info < (3,):
        raise Exception("PICO requires Python version 3.X. " + skipmsg)

    def checklib(lib, name, version):
        try:
            mod = __import__(lib)
            try:
                mod_version = Version(mod.__version__)
                min_version = Version(version)
                if mod_version < min_version:
                    raise Exception(f"PICO requires {name} (>= {version}). You have {mod.__version__}. {skipmsg}")
            except InvalidVersion:
                print(f"Warning: Could not parse version of {name}, skipping version check.")
        except ImportError:
            raise Exception(f"PICO requires {name}. {skipmsg}")

    checklib('numpy', 'NumPy', '1.6.1')
    checklib('scipy', 'SciPy', '0.10.1')

# --- Optional cython compilation ---
build_cython = '--build_cython' in sys.argv
if build_cython:
    sys.argv.remove('--build_cython')
    from Cython.Build import cythonize
    ext_modules = cythonize([
        Extension('pypico.pico', ['pypico/pico.pyx'],
                  extra_compile_args=os.environ.get('CFLAGS', '').split() + os.environ.get('CPPFLAGS', '').split(),
                  extra_link_args=os.environ.get('LDFLAGS', '').split(),
                  include_dirs=['/usr/include/python3.11/cpython', sysconfig.get_path('include')])
    ])
else:
    ext_modules = [
        Extension('pypico.pico', ['pypico/pico.c'],
                  extra_compile_args=os.environ.get('CFLAGS', '').split() + os.environ.get('CPPFLAGS', '').split(),
                  extra_link_args=os.environ.get('LDFLAGS', '').split(),
                  include_dirs=['/usr/include/python3.11/cpython', sysconfig.get_path('include')])
    ]

# --- Setup ---
setup(
    name='pypico',
    version='4.0.0',
    author='Marius Millea',
    author_email='mariusmillea@gmail.com',
    packages=['pypico'],
    url='https://github.com/marius311/pypico',
    license='LICENSE.txt',
    description='Quickly compute the CMB powerspectra and matter transfer functions.',
    long_description=open('README.md').read(),
    long_description_content_type='text/markdown',
    ext_modules=ext_modules,
    include_package_data=True,
    package_data={
        'pypico': ['fpico_interface.f90', 'pico.h'],
        'plugins': ['camb/*']
    },
    install_requires=[
        'numpy>=1.6.1',
        'scipy>=0.10.1',
        'cython; extra == "cython"'
    ],
    classifiers=[
        'Programming Language :: Python :: 3',
        'Operating System :: OS Independent',
    ]
)
