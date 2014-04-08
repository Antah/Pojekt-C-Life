Pojekt-C-Life
=============
    Obsluga Gry w zycie
  
    Przykładowe polecenie uruchomienia programu:
  ./life -f dane.txt -p gen -n 10 -s 10 -x 20 -y 20
  
    Aby program mogl dzialac i wyliczac generacje potrzebny jest plik tekstowy z danymi.
  Przykladowy format pliku z danymi:
  4 4
  0 0 0 0
  0 1 1 0
  0 1 1 0
  0 0 0 0
  
    Oprocz tego przy uruchomieniu programu wymagane sa nastepujace flagi:
      -f nazwa  - nazwa pliku txt z danymi o formacie podanym powyzej.
      -p sciezka  - sciezka do miejsca, w ktorym program ma zapisywac wyliczone generacje.
      -n liczba -  liczba egenracji do wyliczenia.
      -s liczba - liczba generacji do zapisania(nie liczac zerowej i ostatniej, ktore program zawsze zapisuje).
      
    Opcjonalne flagi to:
      -x liczba - szerokosc pojedynczej komorki w pikselach(domyslnie 15).
      -y liczba - wysokosc pojedynczej komorki w pikselach(domyslnie 15).
  
  Autor:
  Karol Tamowicz
