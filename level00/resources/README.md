# level00

## Contexte

Rien d'intéressant dans le home de `level00`.

## Recherche

On cherche tous les fichiers appartenant à `flag00` :

```bash
find / -user flag00 2>/dev/null
```

On trouve :

```text
/usr/sbin/john
```

Son contenu :

```bash
cat /usr/sbin/john

cdiiddwpgswtgt
```

## Vulnérabilité

Pas vraiment de vulnérabilité ici.

Le mot de passe est simplement caché avec un chiffrement de César (ROT11).

## Exploitation

On décale les lettres avec `tr` (on peut également utiliser des outils en ligne comme `CyberChef` ou `dCode`) :

```bash
cat /usr/sbin/john | tr 'a-z' 'l-za-k'
```

Résultat :

```text
nottoohardhere
```

Il ne reste plus qu'à l'utiliser pour se connecter à `flag00` puis à utiliser la commande `getflag`, ici :

```
x24ti5gi3x0ol2eh4esiuxias
```

## Ressources

- `find`
- `tr`