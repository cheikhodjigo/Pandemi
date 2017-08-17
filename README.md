# pandemi.c

## TODOlist

* [] ajouter mon dépôt sur Gitlab
* [] configurer mon dépôt comme privé
* [] modifier le fichier `.gitignore`
* [] implémenter le fichier `pandemi.c`
* [] implémenter la cible `bin/pandemic` dans le Makefile
* [] vérifier mon travail avec le script `tests.sh`
* [] rédiger le fichier `README.md`

## Tests

Lancez les tests avec la commande suivante:

~~~sh
./tests.sh
~~~

ou via le Makefile

~~~sh
make tests
~~~

**Vous devez implémenter la cible `bin/pandemic` dans le fichier Makefile pour utiliser
le script de tests.**

### Format des tests

Le script de tests s'occupe de compiler le programme `pandemic` en utilisant le
Makefile puis de l'exécuter avec les tests trouvés dans le répertoire `tests/`.

Le format des cas de tests est le suivant:
* `test_XX.args` nombre de jour à simuler à passer en argument au programme
* `test_XX.in` carte à saisir dans stdin
* `test_XX.res` sortie attendue (stdout et stderr confondus)

### Générateur de cartes

Le programme `generator` permet de générer des cartes de configuration aléatoirement.
Très pratique pour écrire vos propres tests!

Usage:
~~~sh
Usage: generator <lignes> <colonnes>
~~~

Exemple d'utilisation:
~~~sh
make bin/generator
bin/generator 5 10
~~~

Affiche:
~~~sh
..X...HX..
..XXX...HH
H..XH.H...
.XHXXXXX..
...HXXH.X.
~~~
