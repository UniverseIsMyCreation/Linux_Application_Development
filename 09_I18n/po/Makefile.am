pkgdata_DATA = ru/LC_MESSAGES/predict_number.mo

ru/LC_MESSAGES/predict_number.mo: ru.po
	mkdir -p `dirname $@`
	msgfmt $< -o $@

ru.po:	messages.pot
	msgmerge -U $@ $<

messages.pot:	predict_number.pot ../src/predict_number.c
	xgettext -k_ -c ../src/predict_number.c -o messages.new.pot
	cp predict_numbe	r.pot messages.pot
	msgmerge -U messages.pot messages.new.pot
