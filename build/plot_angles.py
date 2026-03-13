import pandas as pd
import matplotlib.pyplot as plt
import numpy as np


df = pd.read_csv('neutron_angles_h1_0.csv', comment='#')


counts = pd.to_numeric(df.iloc[:, 0], errors='coerce').dropna().values


counts = counts[1:-1]


angles = np.linspace(0, 180, len(counts))

plt.figure(figsize=(10, 6))


plt.bar(angles, counts, width=(180/len(counts)), color='purple', alpha=0.8, edgecolor='black')

plt.title('Neutron Scattering Angles: AlCoCrFeNi (Target: 10x3 cm)')
plt.xlabel('Scattering Angle (degrees)')
plt.ylabel('Neutron Count')
plt.grid(True, linestyle='--', alpha=0.6)

plt.savefig('spallation_report_new.png')
print("График успешно исправлен и сохранен!")
plt.show()