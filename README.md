Grafika, 2 užduotis
===================

Kompiuterinė grafika, Programų sistemų kurso 7 semestras, 2 atsiskaitomasis darbas

Užduotis
========

- Rasti pagrindines 4 transformacijas;
- Parašyti OpenGL programą, kuri generuotų tą patį paveiksliuką, kurio atskiros dalys (atitinkančiomis skirtingas transformacijas po pirmos iteracijos) nuspalvintos skirtingomis spalvomis;
- Sukurti tą patį paveiksliuką iš atskirų taškų tikimybiniu metodu:
	- (0) padėti kokį nors pradinį tašką p;
	- (1) pritaikyti vieną iš 4 transformacijų p := T(p) su tikimybe proporcinga tos dalies dydžiui; pavaizduoti p;
	- (2) kartoti (1) pakankamai daug kartų.

Veikimas
========

Pateiktos dvi programos piešiančios panašų fraktalinį paeiksliuką. Viena iš jų pritaiko standartini fraktalų algoritmą, o kita - atskirų taškų tikimybinių metodu. Abiejų programų žingsnio valdiklis - tarpo (spacebar) klavišas. Paleidimas

*fraktalai-t.c* - standartinis fraktalo piešimas. *make run*

*fraktalai-ifs.c* - tikimybinis modelis. *make ifs*
