# TP1: `pandemi.c`

## Description

Ce travail est un programme qui permet de montrer l'evolution d'un virus au sein d'une population.
Il est effectue dans le cadre du tp1 du cours d'INF3135(Construction et maintenance de locigiel).
Ce cours est donne au trimestre d'Automne 2017 par Alexandre Blondin Masse.Il est offert par 
l'universite du Quebec a Montreal.

## Auteur

Prenom : Cheikh Omar
Nom: DJIGO

## Fonctionnement

Pour executer le programme on devra tout d'abord entrer la commande 'make' au 
terminal. Cette commande servira a compiler le programme. On pourra ensuite 
rentrer la commande 'bin/pandemic'.Cela aura pour effet de lancer le programme.
Cette commande peut aussi etre suivi du nombre de jours a simuler(il doit etre
compris entre 0 et 100). C'est le seul argument qui sera accepter. Ceci fait,
vous devez entrer sur stdin la carte de la population. Cette carte doit etre
composer de 40 * 20 caractere. Ces caracteres peuvent entrer de facon continue
ou de facon discontinue. La maniere discontinue exige que l'on rentre 40 
caracteres sur 20 differentes lignes. Les seules caracteres admis sont les suivants:
'.', 'H' et 'X'. Tout autre caracteres entres generera une erreur. Une carte trop 
courte generera aussi une erreur. 
    
## Tests

En tout temps, il est possible de tester le programme en lançant la commande

```sh
./tests.sh
```

ou à l'aide de la cible `check` du Makefile

```sh
make check
```

**Remarque:** Vous devez d'abord implémenter la cible `bin/pandemic` dans le
fichier Makefile pour utiliser le script de tests.

### Format des tests

Le script de tests s'occupe de compiler le programme `pandemic` en utilisant le
Makefile puis de l'exécuter avec les tests trouvés dans le répertoire `tests/`.

Le format des cas de tests est le suivant:

* `test_XX.args` nombre de jour à simuler à passer en argument au programme
* `test_XX.in` carte à saisir dans `stdin`
* `test_XX.res` sortie attendue (`stdout` et `stderr` confondus)

### Générateur de cartes

Le programme `generator` permet de générer des cartes de configuration aléatoirement.
Il est très pratique pour tester votre programme.

Usage:
```sh
Usage: generator <lignes> <colonnes>
```

Exemple d'utilisation:
```sh
make bin/generator
bin/generator 5 10
```

Affiche:
```sh
..X...HX..
..XXX...HH
H..XH.H...
.XHXXXXX..
...HXXH.X.
```

## Références

Nous avons cloner le projet a partir de l'URL suivant: https://gitlab.com/Morriar/inf3135-aut2017-tp1.

## État du projet

Indiquez toutes les tâches qui ont été complétés en insérant un `X` entre les
crochets. Si une tâche n'a pas été complétée, expliquez pourquoi.

* [X] Le nom du dépôt GitLab est exactement `inf3135-aut2017-tp1` (Pénalité de
  **50%**).
* [X] L'URL du dépôt GitLab est exactement (remplacer `utilisateur` par votre
  nom identifiant GitLab) `https://gitlab.com/utilisateur/inf3135-aut2017-tp1`
  (Pénalité de **50%**).
* [X] L'utilisateur `ablondin` (groupe 20) ou `Morriar` (groupe 40) a accès au
  projet en mode *Developer* (Pénalité de **50%**).
* [X] Le dépôt GitLab est privé (Pénalité de **50%**).
* [X] Le fichier `.gitignore` a été mis à jour.
* [X] Le fichier `pandemi.c` a été implémenté.
* [X] La cible `bin/pandemic` a été ajoutée dans le Makefile.
* [X] Aucun test exécuté avec la commande `make check` n'échoue.
* [X] Les sections incomplètes du fichier `README.md` ont été complétées.
