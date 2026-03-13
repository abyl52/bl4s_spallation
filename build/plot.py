import pandas as pd
import matplotlib.pyplot as plt
import os

file_name = 'neutron_angles_h1_0.csv'

try:
    df = pd.read_csv(file_name, comment='#')
    # Берем данные без underflow/overflow
    counts = df['entries'].iloc[1:-1].tolist()
    
    # ПРОВЕРКА: Считаем сумму всех нейтронов
    total_neutrons = sum(counts)
    print(f"📊 Total number of neutrons on the graph: {total_neutrons}")
    
    angles = list(range(len(counts)))
    
    plt.figure(figsize=(10, 6))
    
    # МЕНЯЕМ ЦВЕТ НА ЗЕЛЕНЫЙ (чтобы точно увидеть обновление)
    plt.bar(angles, counts, width=1.0, align='edge', color='seagreen', edgecolor='black')
    
    plt.title(f'Angular distribution (Total: {total_neutrons} particles)')
    plt.xlabel('Angle (degrees)')
    plt.ylabel('Quantity')
    
    # Сохраняем с НОВЫМ ИМЕНЕМ, чтобы VS Code не тупил с кешем
    output_name = 'test_plot_new.png'
    plt.savefig(output_name, dpi=300)
    print(f"✅ Новый график сохранен как: {output_name}")

except Exception as e:
    print(f"❌ Ошибка: {e}")