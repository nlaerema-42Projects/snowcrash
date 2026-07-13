# level09

## Contexte

On trouve deux fichiers dans le home de `level09` :

```text
level09
token
```

Le fichier `token` n'est pas lisible directement.

## Recherche

On exécute le programme sur une chaîne de caractères :

```bash
./level09 test
```

Résultat :

```text
tfuw
```

On remarque que chaque caractère est décalé en fonction de sa position dans la chaîne.

Le même traitement est appliqué au fichier `token`.

## Vulnérabilité

Il n'y a pas réellement de vulnérabilité.

Le programme applique simplement un encodage très simple au contenu du fichier `token`.

Comme l'algorithme est réversible, il suffit d'effectuer l'opération inverse pour retrouver le mot de passe.

## Exploitation

On récupère le contenu du fichier :

```bash
cat token
```

Puis on applique l'opération inverse avec un petit script :

```python
s = "..."   # contenu du fichier token

for i, c in enumerate(s):
    print(chr(ord(c) - i), end="")
```

On obtient le mot de passe de `flag09`.

Il ne reste plus qu'à se connecter puis lancer `getflag` :

```text
s5cAJpM8ev6XHw998pRWG728z
```

## Ressources

- Encodage de caractères
- Scripting