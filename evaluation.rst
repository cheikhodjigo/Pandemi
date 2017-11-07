Correction du TP1
~~~~~~~~~~~~~~~~~

Grille de points
================

+--------------------+----------------------------------------+--------+---------+
| Critère            | Description                            | Note   | Sur     |
+====================+========================================+========+=========+
|                    |                                        |        |         |
| Fonctionnabilité   | 14 tests, -3 points par test échoué    | 34     | 40      |
|                    |                                        |        |         |
+--------------------+----------------------------------------+--------+---------+
|                    |                                        |        |         |
| Qualité du code    | Identifiants, indentation, simplicité  |        |         |
|                    | simplicité, lisibilité, commentaires,  | 8      | 20      |
|                    | division en fonctions, constantes      |        |         |
|                    |                                        |        |         |
+--------------------+----------------------------------------+--------+---------+
|                    |                                        |        |         |
|                    | Fichier README complet, utilisant bien |        |         |
| Documentation      | le format Markdown, en-tête de         | 9      | 15      |
|                    | fichiers, *docstrings*                 |        |         |
|                    |                                        |        |         |
+--------------------+----------------------------------------+--------+---------+
|                    | Compilation, nettoyage et              |        |         |
| Makefile           | tests (``make``, ``make clean``        | 0      | 10      |
|                    | et ``make check``)                     |        |         |
+--------------------+----------------------------------------+--------+---------+
|                    | Décomposition en petits *commits*,     |        |         |
| Utilisation de Git | fichier ``.gitignore`` mis à jour,     | 15     | 15      |
|                    | messages soignés et significatifs      |        |         |
+--------------------+----------------------------------------+--------+---------+
| **Total**                                                   | **66** | **100** |
+--------------------+----------------------------------------+--------+---------+

Commentaires
============

- J'ai dû modifier le Makefile pour que ça compile. Comme il s'agit du premier
  test, ça aurait dû être corrigé avant la remise. Je mets donc 0/10 pour la
  partie Makefile, car c'est la base.
- Tests réussis: 12/14. Les tests 6 et 7 échouent.
- La qualité du code pourrait être mieux. Bonne division en fonctions. Mauvaise
  aération (espacement) autour des opérateurs/délimiteurs. Beaucoup de valeurs
  magiques. La matrice est une variable globale, ce qui est une très mauvaise
  pratique (certains cours pénalisent très fortement cet aspect). Éviter de
  mettre des commentaires dans le code.
- Dans l'en-tête du fichier, indiquer l'auteur. Les *docstrings* sont là, mais
  pourraient être un peu mieux formatées (sauter une ligne après la
  description), mieux aérer. README correct, mais pourrait être mieux. Formater
  les bouts de code à l'aide du format Markdown. Aussi, la description du
  fonctionnement est lourde à lire. Utiliser des paragraphes, mettre des
  commandes en exemples, etc. Plusieurs fautes de frappe et de français. Ne pas
  omettre les accents, c'est du texte, pas du code.
- Makefile non fonctionnel.
- Excellente utilisation de Git.
