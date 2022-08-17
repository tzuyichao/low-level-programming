## Check verison


```
dpkg -l libgtk2.0-0 libgtk-3-0
```

## set version

```
imports.gi.versions.Gtk = "3.0";
```


hello world example
```
imports.gi.versions.Gtk = "3.0";
const Gtk = imports.gi.Gtk;

let app = new Gtk.Application({ application_id: 'org.gtk.ExampleApp' });

app.connect('activate', () => {
    let win = new Gtk.ApplicationWindow( {application: app} );
    let btn = new Gtk.Button( {label: 'Hello, World!'} );
    btn.connect('clicked', () => { win.close(); });
    win.add(btn);
    win.show_all();
});

app.run([]);

```
