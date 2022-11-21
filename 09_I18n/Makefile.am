bin_PROGRAMS=predict_number
predict_number_SOURCES =predict_number.c
pkgdata_DATA=update_pot_po ru/LC_MESSAGES/predict_number.mo

init_pot_po:    predict_number.pot
        msginit -i predict_number.pot -o ru.po -l ru

ru/LC_MESSAGES/predict_number.mo:  ru.po
        mkdir -p `dirname $@`
        msgfmt $< -o $@

ru.po:  predict_number.pot
        msgmerge -U $@ $<

predict_number.pot:    predict_number.c
        xgettext -k_ -c predict_number.c -o predict_number.new.pot
        msgmerge -U predict_number.pot predict_number.new.pot
        rm predict_number.new.pot

update_pot_po:  predict_number.pot ru.po

english:    predict_number
        ./predict_number

russian:    predict_number
        LANGUAGE=ru_RU PO_LOCAL=1 ./predict_number

clean:
		git clean -df