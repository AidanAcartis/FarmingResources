# ModifyFarming

## Description

`ModifyFarming` est un programme C++ qui simule le déplacement de troupes sur un terrain en forme de grille hexagonale, en évitant les obstacles. Il calcule le chemin le plus court depuis la position initiale des troupes jusqu’à un camp de bûcherons, et compare le temps nécessaire pour les troupes amies et ennemies.

Le programme prend en compte :

* Les troupes amies et ennemies avec leurs vitesses.
* Les cellules impassables.
* Les mouvements possibles sur un terrain hexagonal.
* La comparaison du temps pour déterminer quelle troupe atteint le camp en premier.

---

## Fichiers

* **ModifyFarming.cpp** :
  Contient l’implémentation principale de l’algorithme de cheminement et des fonctions pour gérer les mouvements et les obstacles.

* **OutputForModifyFarming.cpp** :
  Exemple d’exécution avec un jeu de données différent (positions initiales des troupes et obstacles).

---

## Fonctionnalités principales

1. Calcul du chemin le plus court vers le camp de bûcherons (`fonction1`, `fonction2`).
2. Gestion des mouvements alternatifs en cas d’obstacles (`forChange`, `choice`).
3. Vérification des cases impassables (`Verif`, `Forbid`).
4. Comparaison des temps de trajet entre troupes amies et ennemies (`solution`).
5. Affichage des positions et des chemins pour débogage (`displayArray`, `displayMatrice`).

---

## Compilation

Pour compiler le programme, utilisez `g++` :

```bash
g++ -o ModifyFarming ModifyFarming.cpp
g++ -o OutputForModifyFarming OutputForModifyFarming.cpp
```

---

## Exécution

```bash
./ModifyFarming
./OutputForModifyFarming
```

Le programme affiche `True` si les troupes amies atteignent le camp avant les ennemis, sinon `False`.

---

## Exemple de données

* Troupes amies : `{17,18,6}`
* Troupes ennemies : `{19,16,6}`
* Camp de bûcherons : `{18,19}`
* Obstacles : `{{17,19},{18,18},{19,18}}`

---

---

