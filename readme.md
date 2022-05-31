# Just another c++ template using CMake and Catch2

Add the following options to CMake generation to enable features:

Enable unit testing:
> -DENABLE_TESTING=yes

Enable coverage testing:
> -DENABLE_COVERAGE=yes

When coverage is enabled a new target called `template_tests_html_coverage` will appear, if you run it, it will start
unit tests and generate a html containing results.
