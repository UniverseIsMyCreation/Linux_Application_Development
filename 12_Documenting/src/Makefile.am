bin_PROGRAMS=predict_number

pkgdata_DATA = predict_number.1

%.1:	%
		-$(HELP2MAN) --no-info --output=$@ --name='@PACKAGE_NAME@' ./$<
