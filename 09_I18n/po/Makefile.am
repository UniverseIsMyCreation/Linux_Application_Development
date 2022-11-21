pkgdata_DATA = ru/LC_MESSAGES/predict_number.mo

ru/LC_MESSAGES/predict_number.mo:	ru.po
		mkdir -p `dirname $@`
		msgfmt $< -o $@

ru.po:	translate.pot
		msgmerge -U $@ $<

translate.pot:	predict_number.pot ../src/predict_number.c
		xgettext -k_ -c ../src/predict_number.c -o translate.new.pot
		cp predict_number.pot translate.pot
		msgmerge -U translate.pot translate.new.pot