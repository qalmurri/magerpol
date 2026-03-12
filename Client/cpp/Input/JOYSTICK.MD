Perbedaan Penting & Catatan:
_bind_methods: Wajib digunakan agar fungsi get_direction() bisa dipanggil dari GDScript atau sistem internal Godot lainnya.
Casting: Di C++, kita harus melakukan explicit casting menggunakan Ref<InputEventScreenTouch> touch_event = event; untuk memeriksa tipe event-nya.
Memory Management: Kita menggunakan get_node<Sprite2D>("Knob") di _ready. Pastikan di scene tree Anda, node Knob adalah anak langsung dari TouchScreenButton ini.
Shape Radius: Kode di atas mengasumsi Anda menggunakan CircleShape2D. Jika menggunakan shape lain, cara mengambil max_distance mungkin perlu disesuaikan.
