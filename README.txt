Pojekt-C-Life
=============
	Obsluga Gry w zycie
    
Przykladowe polecenie uruchomienia programu:
	./life -f dane.txt -p gen -n 10 -s 10 -x 20 -y 20
  
Aby program mogl dzialac i wyliczac generacje potrzebny jest plik tekstowy z danymi.
Przyk?adowy format pliku z danymi:
	4 4
	0 0 0 0
	0 1 1 0
	0 1 1 0
	0 0 0 0
  
Oprocz tego przy uruchomieniu programu wymagane sa nastepujace flagi:
	-f nazwa	- nazwa pliku txt z danymi o formacie podanym powy?ej.
	-p sciezka	- sciezka do miejsca, w ktorym program ma zapisywa? wyliczone generacje.
	-n liczba	- liczba generacji do wyliczenia.
	-s liczba	- liczba generacji do zapisania(nie liczac zerowej i ostatniej, ktore program zawsze zapisuje).
    
Opcjonalne flagi to:
	-x liczba	- szerokosc pojedynczej komorki w pikselach(domyslnie 15).
	-y liczba	- wysokosc pojedynczej komorki w pikselach(domyslnie 15).
  

Program napisany w CodeBlocks, sprawdzone dzialanie na Windows 7, Ubuntu oraz lenie poprzez Putty.
Link do repozytorium: https://github.com/Antah/Pojekt-C-Life

Autor:
Karol Tamowicz
